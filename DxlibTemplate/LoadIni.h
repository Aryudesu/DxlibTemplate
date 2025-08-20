#pragma once
#include <string>
#include <vector>
#include <optional>   // 追加
#include <stdexcept>  // 追加

class INIDat {
    // 既存フィールド
    std::vector<std::string> Section;
    std::vector<std::vector<std::vector<std::string>>> SDList;

public:
    INIDat();
    INIDat(std::string FileName);
    ~INIDat();

    // 既存
    void DataInput(std::string FileName);
    void DataDelete();
    int  GetSecNum(std::string Sec);
    bool CheckSec(std::string Sec);
    bool CheckElem(std::string Sec, std::string Elem);
    std::vector<std::string> GetData(std::string Sec, std::string Elem);
    //void ShowAllData();

    // === ここから追加の“使い勝手API”（壊さない拡張） ===
    // 値が無い時は def を返す系（例外なし）
    std::string GetStr(const std::string& sec, const std::string& key,
        const std::string& def = "") const;
    int         GetInt(const std::string& sec, const std::string& key,
        int def = 0) const;
    float       GetFloat(const std::string& sec, const std::string& key,
        float def = 0.0f) const;
    bool        GetBool(const std::string& sec, const std::string& key,
        bool def = false) const;

    // 配列（文字列 / int / float）
    std::vector<std::string> GetStrList(const std::string& sec, const std::string& key) const;
    std::vector<int>         GetIntList(const std::string& sec, const std::string& key) const;
    std::vector<float>       GetFloatList(const std::string& sec, const std::string& key) const;

    // 見つからなければ std::nullopt を返す安全系
    std::optional<std::vector<std::string>>
        TryGet(const std::string& sec, const std::string& key) const;

private:
    // 内部ユーティリティ（function.h 依存を排除）
    static std::string trim_copy(const std::string& s);
    static std::vector<std::string> split_eq(const std::string& s);  // '=' で1回
    static std::vector<std::string> split_csv(const std::string& s); // ',' で全分割
    static bool is_array_rhs(const std::string& s); // 右辺に','含むかで判定
    static bool iequals(const std::string& a, const std::string& b); // 大小無視比較
};
