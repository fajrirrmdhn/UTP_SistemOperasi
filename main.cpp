#include <iostream>

using namespace std;

// 1. FUNGSI FCFS (FIRST COME FIRST SERVED)
void fcfs(int n, int pid[], int at[], int bt[], float &avg_wt, float &avg_tat) {
    int ct[50], tat[50], wt[50];
    bool selesai[50] = {false};
    int urutan[50], start_time[50], end_time[50];

    int waktu_sekarang = 0;
    int selesai_count = 0;

    while (selesai_count < n) {
        int terpilih = -1;
        int min_at = 999999;

        for (int i = 0; i < n; i++) {
            if (!selesai[i] && at[i] <= waktu_sekarang) {
                if (at[i] < min_at) {
                    min_at = at[i];
                    terpilih = i;
                }
            }
        }

        if (terpilih == -1) {
            int at_terdekat = 999999;
            for (int i = 0; i < n; i++) {
                if (!selesai[i] && at[i] < at_terdekat) {
                    at_terdekat = at[i];
                }
            }
            waktu_sekarang = at_terdekat;
            continue;
        }

        start_time[selesai_count] = waktu_sekarang;
        waktu_sekarang += bt[terpilih];
        end_time[selesai_count] = waktu_sekarang;

        ct[terpilih] = waktu_sekarang;
        tat[terpilih] = ct[terpilih] - at[terpilih];
        wt[terpilih] = tat[terpilih] - bt[terpilih];

        selesai[terpilih] = true;
        urutan[selesai_count] = terpilih;
        selesai_count++;
    }

    cout << "\n=================================================================\n";
    cout << "           HASIL: FIRST COME FIRST SERVED (FCFS)\n";
    cout << "=================================================================\n";
    cout << "Urutan Eksekusi: ";
    for (int i = 0; i < n; i++) {
        int idx = urutan[i];
        cout << "P" << pid[idx] << " [" << start_time[i] << "-" << end_time[i] << "]";
        if (i < n - 1) cout << " -> ";
    }
    cout << "\n\n";

    cout << "Proses\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "-------------------------------------------------\n";

    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";

        total_wt += wt[i];
        total_tat += tat[i];
    }

    avg_wt = total_wt / n;
    avg_tat = total_tat / n;

    cout << "-------------------------------------------------\n";
    cout << "Rata-rata Waiting Time (WT)     : " << avg_wt << "\n";
    cout << "Rata-rata Turn Around Time (TAT): " << avg_tat << "\n";
    cout << "=================================================================\n";
}

// 2. FUNGSI SJF NON-PREEMPTIVE (SHORTEST JOB FIRST)
void sjf(int n, int pid[], int at[], int bt[], float &avg_wt, float &avg_tat) {
    int ct[50], tat[50], wt[50];
    bool selesai[50] = {false};
    int urutan[50], start_time[50], end_time[50];

    int waktu_sekarang = 0;
    int selesai_count = 0;

    while (selesai_count < n) {
        int terpilih = -1;
        int min_bt = 999999;

        for (int i = 0; i < n; i++) {
            if (!selesai[i] && at[i] <= waktu_sekarang) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    terpilih = i;
                } else if (bt[i] == min_bt) {
                    if (at[i] < at[terpilih]) {
                        terpilih = i;
                    }
                }
            }
        }

        if (terpilih == -1) {
            int at_terdekat = 999999;
            for (int i = 0; i < n; i++) {
                if (!selesai[i] && at[i] < at_terdekat) {
                    at_terdekat = at[i];
                }
            }
            waktu_sekarang = at_terdekat;
            continue;
        }

        start_time[selesai_count] = waktu_sekarang;
        waktu_sekarang += bt[terpilih];
        end_time[selesai_count] = waktu_sekarang;

        ct[terpilih] = waktu_sekarang;
        tat[terpilih] = ct[terpilih] - at[terpilih];
        wt[terpilih] = tat[terpilih] - bt[terpilih];

        selesai[terpilih] = true;
        urutan[selesai_count] = terpilih;
        selesai_count++;
    }

    cout << "\n=================================================================\n";
    cout << "     HASIL: SHORTEST JOB FIRST (SJF) NON-PREEMPTIVE\n";
    cout << "=================================================================\n";
    cout << "Urutan Eksekusi: ";
    for (int i = 0; i < n; i++) {
        int idx = urutan[i];
        cout << "P" << pid[idx] << " [" << start_time[i] << "-" << end_time[i] << "]";
        if (i < n - 1) cout << " -> ";
    }
    cout << "\n\n";

    cout << "Proses\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "-------------------------------------------------\n";

    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";

        total_wt += wt[i];
        total_tat += tat[i];
    }

    avg_wt = total_wt / n;
    avg_tat = total_tat / n;

    cout << "-------------------------------------------------\n";
    cout << "Rata-rata Waiting Time (WT)     : " << avg_wt << "\n";
    cout << "Rata-rata Turn Around Time (TAT): " << avg_tat << "\n";
    cout << "=================================================================\n";
}

// 3. FUNGSI HRRN NON-PREEMPTIVE (HIGHEST RESPONSE RATIO NEXT)
void hrrn(int n, int pid[], int at[], int bt[], float &avg_wt, float &avg_tat) {
    int ct[50], tat[50], wt[50];
    bool selesai[50] = {false};
    int urutan[50], start_time[50], end_time[50];

    int waktu_sekarang = 0;
    int selesai_count = 0;
    int langkah = 1;

    cout << "\n=================================================================\n";
    cout << "      LOG PERHITUNGAN RESPONSE RATIO (HRRN NON-PREEMPTIVE)\n";
    cout << "             Rumus RR = (WT + BT) / BT\n";
    cout << "=================================================================\n";

    while (selesai_count < n) {
        int kandidat_count = 0;
        for (int i = 0; i < n; i++) {
            if (!selesai[i] && at[i] <= waktu_sekarang) {
                kandidat_count++;
            }
        }

        if (kandidat_count == 0) {
            int at_terdekat = 999999;
            for (int i = 0; i < n; i++) {
                if (!selesai[i] && at[i] < at_terdekat) {
                    at_terdekat = at[i];
                }
            }
            waktu_sekarang = at_terdekat;
            continue;
        }

        cout << "\n[Langkah #" << langkah << "] Waktu Saat Ini = " << waktu_sekarang << "\n";
        cout << "Proses\tAT\tBT\tWT\tRumus (WT+BT)/BT\tResponse Ratio\n";
        cout << "----------------------------------------------------------------\n";

        int terpilih = -1;
        float max_rr = -1.0;

        for (int i = 0; i < n; i++) {
            if (!selesai[i] && at[i] <= waktu_sekarang) {
                int waktu_tunggu = waktu_sekarang - at[i];
                float rr = (float)(waktu_tunggu + bt[i]) / bt[i];

                cout << "P" << pid[i] << "\t"
                     << at[i] << "\t"
                     << bt[i] << "\t"
                     << waktu_tunggu << "\t("
                     << waktu_tunggu << " + " << bt[i] << ") / " << bt[i] << "\t\t"
                     << rr << "\n";

                if (rr > max_rr) {
                    max_rr = rr;
                    terpilih = i;
                }
            }
        }
        cout << ">> Dipilih: P" << pid[terpilih] << " (RR Tertinggi = " << max_rr << ")\n";

        start_time[selesai_count] = waktu_sekarang;
        waktu_sekarang += bt[terpilih];
        end_time[selesai_count] = waktu_sekarang;

        ct[terpilih] = waktu_sekarang;
        tat[terpilih] = ct[terpilih] - at[terpilih];
        wt[terpilih] = tat[terpilih] - bt[terpilih];

        selesai[terpilih] = true;
        urutan[selesai_count] = terpilih;
        selesai_count++;
        langkah++;
    }

    cout << "\n=================================================================\n";
    cout << "  HASIL AKHIR: HIGHEST RESPONSE RATIO NEXT (HRRN) NON-PREEMPTIVE\n";
    cout << "=================================================================\n";
    cout << "Urutan Eksekusi: ";
    for (int i = 0; i < n; i++) {
        int idx = urutan[i];
        cout << "P" << pid[idx] << " [" << start_time[i] << "-" << end_time[i] << "]";
        if (i < n - 1) cout << " -> ";
    }
    cout << "\n\n";

    cout << "Proses\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "-------------------------------------------------\n";

    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";

        total_wt += wt[i];
        total_tat += tat[i];
    }

    avg_wt = total_wt / n;
    avg_tat = total_tat / n;

    cout << "-------------------------------------------------\n";
    cout << "Rata-rata Waiting Time (WT)     : " << avg_wt << "\n";
    cout << "Rata-rata Turn Around Time (TAT): " << avg_tat << "\n";
    cout << "=================================================================\n";
}

int main() {
    char npm[50] = "2517051041";
    int pid[50], at[50], bt[50];
    int n = 0;

    cout << "=================================================================\n";
    cout << "     SIMULASI PENJADWALAN CPU BERDASARKAN NPM MAHASISWA          \n";
    cout << "=================================================================\n";
    cout << "NPM: " << npm << endl;

    while (npm[n] != '\0') {
        n++;
    }

    int max_digit = -1;
    int idx_digit_terbesar = -1;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;

        at[i] = npm[i] - '0';
        bt[i] = npm[n - 1 - i] - '0';

        if (bt[i] == 0) {
            bt[i] = 10;
        }

        int digit_saat_ini = npm[i] - '0';
        if (digit_saat_ini > max_digit) {
            max_digit = digit_saat_ini;
            idx_digit_terbesar = i;
        }
    }

    if (idx_digit_terbesar != -1) {
        at[idx_digit_terbesar] = 0;
    }

    cout << "\n=================================================================\n";
    cout << "               DATA PROSES DARI DIGIT NPM: " << npm << "\n";
    cout << "=================================================================\n";
    cout << "Proses\tDigit NPM\tAT Akhir\tBT Akhir\tKeterangan\n";
    cout << "-----------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << npm[i] << "\t\t"
             << at[i] << "\t\t"
             << bt[i] << "\t\t";
        if (i == idx_digit_terbesar) {
            cout << "AT diubah ke 0 (Digit terbesar: " << max_digit << ")";
        } else if (npm[n - 1 - i] == '0') {
            cout << "BT diubah dari 0 ke 10";
        }
        cout << "\n";
    }
    cout << "=================================================================\n";

    float fcfs_wt = 0, fcfs_tat = 0;
    float sjf_wt = 0, sjf_tat = 0;
    float hrrn_wt = 0, hrrn_tat = 0;

    fcfs(n, pid, at, bt, fcfs_wt, fcfs_tat);
    sjf(n, pid, at, bt, sjf_wt, sjf_tat);
    hrrn(n, pid, at, bt, hrrn_wt, hrrn_tat);

    cout << "\n=================================================================\n";
    cout << "          TABEL PERBANDINGAN RATA-RATA KETIGA ALGORITMA          \n";
    cout << "=================================================================\n";
    cout << "Algoritma\t\t\tRata-rata WT\tRata-rata TAT\n";
    cout << "-----------------------------------------------------------------\n";
    cout << "FCFS\t\t\t\t" << fcfs_wt << "\t\t" << fcfs_tat << "\n";
    cout << "SJF Non-Preemptive\t\t" << sjf_wt << "\t\t" << sjf_tat << "\n";
    cout << "HRRN Non-Preemptive\t\t" << hrrn_wt << "\t\t" << hrrn_tat << "\n";
    cout << "=================================================================\n\n";

    return 0;
}
